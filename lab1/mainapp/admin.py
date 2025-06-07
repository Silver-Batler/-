from django.contrib import admin
from .models import Book

@admin.register(Book)
class BookAdmin(admin.ModelAdmin):
    """
    Настройка отображения модели Book в административной панели Django.
    """
    list_display = ('title', 'author', 'publication_year', 'genre', 'pages', 'rating', 'is_bestseller')
    list_filter = ('genre', 'is_bestseller', 'publication_year')
    search_fields = ('title', 'author')
    ordering = ('-rating', 'title')

