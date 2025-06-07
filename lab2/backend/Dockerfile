FROM python:3.11-slim

# Установка переменных окружения
ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1

# Установка рабочей директории
WORKDIR /app

# Установка зависимостей для netcat
RUN apt-get update && apt-get install -y netcat-openbsd && apt-get clean

# Копирование и установка зависимостей
COPY requirements.txt /app/
RUN pip install --no-cache-dir -r requirements.txt

# Копирование исходного кода
COPY . /app/

# Создание директории для статических файлов
RUN mkdir -p /app/staticfiles

# Установка прав на выполнение entrypoint.sh
RUN chmod +x /app/entrypoint.sh

# Установка entrypoint
ENTRYPOINT ["/app/entrypoint.sh"]

# Запуск команды при старте контейнера
CMD ["gunicorn", "--bind", "0.0.0.0:8000", "lab1.wsgi:application"]

