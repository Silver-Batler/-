import random
import datetime
from .models import Book
from django.db import transaction
from faker import Faker

# Инициализация Faker
fake = Faker()

def gentestdata():
    """
    Функция для генерации тестовых данных и заполнения базы данных.
    Создает 100 случайных книг.
    """
    try:
        with transaction.atomic():
            for i in range(100):
                # Генерация случайных данных для книги
                book = Book()
                book.title = fake.catch_phrase()
                book.author = fake.name()
                book.publication_year = random.randint(1900, 2025)
                book.genre = random.choice([choice[0] for choice in Book.GENRE_CHOICES])
                book.pages = random.randint(50, 1000)
                book.rating = round(random.uniform(1, 10), 1)
                book.is_bestseller = random.random() > 0.7
                book.save()
        
        print('Тестовые данные успешно сгенерированы!')
    except Exception as e:
        print(f'Ошибка при генерации тестовых данных: {e}')

