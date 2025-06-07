# Лабораторная работа №1: Трёхуровневая клиент-серверная архитектура

## Описание
Проект представляет собой REST API для управления каталогом книг. Реализован с использованием Django и Django REST Framework.

## Требования
- Python 3.9+
- Django
- Django REST Framework
- PostgreSQL
- Другие зависимости указаны в requirements.txt

## Установка и запуск

### 1. Установка зависимостей
```bash
pip install -r requirements.txt
```

### 2. Настройка базы данных PostgreSQL
```bash
# Создание пользователя и базы данных
sudo -u postgres psql
postgres=# CREATE USER django WITH PASSWORD '2NevjFoQisyVaV';
postgres=# CREATE DATABASE lab1_db OWNER django;
postgres=# \q
```

### 3. Применение миграций
```bash
python manage.py makemigrations
python manage.py migrate
```

### 4. Создание суперпользователя
```bash
python manage.py createsuperuser
```

### 5. Заполнение базы данных тестовыми данными
```bash
python manage.py shell
>>> from mainapp.gentestdata import *
>>> gentestdata()
>>> exit()
```

### 6. Запуск сервера
```bash
python manage.py runserver
```

## API Endpoints

- `GET /api/books/` - Получение списка всех книг
- `GET /api/books/{id}/` - Получение информации о конкретной книге
- `POST /api/books/` - Создание новой книги
- `PUT /api/books/{id}/` - Обновление информации о книге
- `PATCH /api/books/{id}/` - Частичное обновление информации о книге
- `DELETE /api/books/{id}/` - Удаление книги

## Модель данных

Модель `Book` содержит следующие поля:
- `title` - Название книги (строка)
- `author` - Автор книги (строка)
- `publication_year` - Год издания (целое число)
- `genre` - Жанр книги (выбор из предопределенного списка)
- `pages` - Количество страниц (положительное целое число)
- `rating` - Рейтинг книги (десятичное число от 0 до 10)
- `is_bestseller` - Является ли книга бестселлером (логическое значение)
- `created_at` - Дата создания записи (автоматически)
- `updated_at` - Дата обновления записи (автоматически)

