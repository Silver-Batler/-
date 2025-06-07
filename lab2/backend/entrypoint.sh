#!/bin/sh

# Ожидание доступности базы данных
echo "Waiting for PostgreSQL..."
while ! nc -z $POSTGRES_HOST $POSTGRES_PORT; do
  sleep 0.1
done
echo "PostgreSQL started"

# Применение миграций
python manage.py migrate

# Создание суперпользователя, если его нет
python manage.py shell -c "from django.contrib.auth.models import User; User.objects.filter(username='admin').exists() or User.objects.create_superuser('admin', 'admin@example.com', 'admin123')"

# Заполнение базы данных тестовыми данными
python manage.py shell -c "from mainapp.gentestdata import gentestdata; gentestdata()"

# Сбор статических файлов
python manage.py collectstatic --noinput

# Запуск сервера
exec "$@"

