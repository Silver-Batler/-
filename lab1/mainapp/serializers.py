from rest_framework import serializers
from .models import Book

class BookSerializer(serializers.ModelSerializer):
    """
    Сериализатор для модели Book.
    Преобразует объекты модели в JSON и обратно.
    """
    class Meta:
        model = Book
        fields = '__all__'

