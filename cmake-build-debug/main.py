import asyncio

from instances import exchange_heart

if __name__ == "__main__":
    asyncio.run(exchange_heart.auto_payer_loop())

