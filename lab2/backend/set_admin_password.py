#!/usr/bin/env python
import os
import django

# Настройка окружения Django
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'lab1.settings')
django.setup()

# Импорт модели User
from django.contrib.auth.models import User

# Установка пароля для пользователя admin
try:
    user = User.objects.get(username='admin')
    user.set_password('admin123')
    user.save()
    print("Пароль для пользователя admin успешно установлен!")
except User.DoesNotExist:
    print("Пользователь admin не найден!")
except Exception as e:
    print(f"Произошла ошибка: {e}")

