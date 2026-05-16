fn lcg(seed: u64, a: u64, c: u64, m: u64) -> impl Iterator<Item = u64> {
    std::iter::successors(Some(seed), move |&value| Some((a.wrapping_mul(value).wrapping_add(c)) % m))
}

fn max_subarray_sum(n: usize, seed: u64, min_val: i32, max_val: i32) -> i64 {
    let range = (max_val - min_val + 1) as u64;
    let random_numbers: Vec<i32> = lcg(seed, 1664525, 1013904223, 1 << 32)
        .take(n)
        .map(|x| (x % range) as i32 + min_val)
        .collect();

    let mut max_sum = i64::MIN;
    for i in 0..n {
        let mut current_sum = 0;
        for j in i..n {
            current_sum += random_numbers[j] as i64;
            if current_sum > max_sum {
                max_sum = current_sum;
            }
        }
    }
    max_sum
}

fn total_max_subarray_sum(n: usize, initial_seed: u64, min_val: i32, max_val: i32) -> i64 {
    let mut total_sum = 0;
    let mut seed = initial_seed;
    let lcg_iter = lcg(initial_seed, 1664525, 1013904223, 1 << 32);

    for _ in 0..20 {
        seed = lcg_iter.next().unwrap();
        total_sum += max_subarray_sum(n, seed, min_val, max_val);
    }
    total_sum
}

fn main() {
    let n = 10000;
    let initial_seed = 42;
    let min_val = -10;
    let max_val = 10;

    let start_time = std::time::Instant::now();
    let result = total_max_subarray_sum(n, initial_seed, min_val, max_val);
    let duration = start_time.elapsed();

    println!("Total Maximum Subarray Sum (20 runs): {}", result);
    println!("Execution Time: {:.6} seconds", duration.as_secs_f64());
}