from rest_framework import viewsets
from .models import Book
from .serializers import BookSerializer

class BookViewSet(viewsets.ModelViewSet):
    """
    ViewSet для модели Book.
    Предоставляет CRUD операции для книг.
    """
    queryset = Book.objects.all()
    serializer_class = BookSerializer

