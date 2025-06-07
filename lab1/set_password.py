from django.contrib.auth.models import User
from django.core.management import setup_environ
import sys
import os

# Добавляем текущий каталог в путь поиска модулей
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

# Импортируем настройки проекта
from lab1 import settings
setup_environ(settings)

# Устанавливаем пароль для пользователя admin
user = User.objects.get(username='admin')
user.set_password('admin123')
user.save()

print("Пароль для пользователя admin успешно установлен!")

