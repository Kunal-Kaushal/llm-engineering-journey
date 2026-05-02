# LLM Engineer — Course Journey

My hands-on practice code for the **[LLM Engineering: Master AI & Large Language Models](https://www.udemy.com/share/10bOXH3@4ckABDK8ReE4JyMgTdDwb7bOeWMQDfL_3WFVE95ouIj6w72khueyTjXnMU3H5O8aAw==/)** Udemy course by **Ed Donner** — an 8-week, project-based program covering the full stack of building with LLMs, from API basics to autonomous multi-agent systems.

---

## Progress

| Week | Topic | Status |
|------|-------|--------|
| 1 | Build Your First LLM Product — Exploring Top Models | Done |
| 2 | Frontier APIs and Customer Service Chatbots | Done |
| 3 | Open-Source Gen AI — Automated Solutions with HuggingFace | — |
| 4 | LLM Showdown — Evaluating Models for Code Gen & Business Tasks | — |
| 5 | Mastering RAG — Vector Embeddings & LangChain | — |
| 6 | Fine-tuning Frontier LLMs with LoRA/QLoRA | — |
| 7 | Advanced Fine-tuning and Competitive Model Building | — |
| 8 | Build Autonomous Multi-Agent Systems | — |

---

## Week 1 — Build Your First LLM Product

**Focus:** LLM foundations, transformer architecture, frontier model APIs

| Day | Notebook | What I built |
|-----|----------|-------------|
| 1 | `day1.ipynb` | Website summarizer using the LLM API |
| 2 | `day2.ipynb` | OpenAI Python SDK — calling any LLM (including local models) via API key |
| 4 | `day4.ipynb` | Web scraping pipeline feeding content into an LLM |
| 5 | `day5.ipynb` | Further Week 1 experiments |

---

## Week 2 — Frontier APIs and Customer Service Chatbots

**Focus:** Multi-modal interactions, Gradio UIs, tool/function calling, multi-LLM orchestration

| File | What I built |
|------|-------------|
| `3LLM.ipynb` | Three LLMs talking to each other in a conversation loop |
| `day1.ipynb` | First Gradio UI integrated with an LLM |
| `day2.ipynb` | Brochure generator — Gradio UI that creates marketing brochures using LLMs |
| `day3.ipynb` | Airline chatbot with full conversation history context in Gradio |
| `day4.ipynb` | Tool calling — gave the LLM a live ticket price lookup tool, progressing from single → multiple → sequential tool calls, backed by a SQLite database |

---

## Course Overview

### Week 3 — Open-Source Gen AI & HuggingFace
Running LLMs locally with Ollama and HuggingFace Hub. **Project:** Tool that creates meeting minutes and action items from audio using open- and closed-source models.

### Week 4 — LLM Evaluation for Code Gen & Business Tasks
Model benchmarking and selection strategies. **Project:** AI that converts Python to optimized C++, boosting performance by 60,000x.

### Week 5 — RAG with Vector Embeddings & LangChain
Semantic search, vector databases, and knowledge integration. **Project:** AI knowledge-worker that becomes an expert on all company-related matters using RAG.

### Week 6 — Fine-tuning with LoRA/QLoRA (Capstone Part A)
Parameter-efficient fine-tuning and data curation. **Project:** Predict product prices from short descriptions using frontier models.

### Week 7 — Advanced Fine-tuning (Capstone Part B)
Fine-tuning open-source models to compete with frontier. **Project:** Execute a fine-tuned open-source model to match frontier performance on price prediction.

### Week 8 — Autonomous Multi-Agent Systems (Capstone Part C)
Agent architectures, multi-model orchestration, autonomous decision-making. **Project:** Autonomous multi-agent system that spots deals and notifies users of bargains.

---

## Tech Stack

| Category | Tools |
|----------|-------|
| LLM Providers | OpenAI (GPT-4), Google Gemini, Meta Llama (via NVIDIA API), Anthropic Claude |
| Open Source | HuggingFace, Ollama |
| RAG & Retrieval | LangChain, Vector Databases |
| Fine-tuning | LoRA / QLoRA |
| UI | Gradio |
| Database | SQLite |
| Deployment | Modal.com, Weights & Biases |
| Runtime | Python 3.12, Jupyter Notebooks |
| Package manager | uv |

---

## Setup

```bash
# Install dependencies
uv sync

# Add your API keys to .env
GOOGLE_API_KEY=...
META_API_KEY=...
OPENAI_API_KEY=...
ANTHROPIC_API_KEY=...
```
