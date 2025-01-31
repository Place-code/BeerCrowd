import asyncio

async def tarefa(nome, duracao):
    print(f"{nome} começou.")
    await asyncio.sleep(duracao)
    print(f"{nome} terminou.")

async def main():
    # Executa várias tarefas em paralelo
    await asyncio.gather(
        tarefa("Tarefa 1", 2),
        tarefa("Tarefa 2", 1),
        tarefa("Tarefa 3", 3)
    )

asyncio.run(main())
