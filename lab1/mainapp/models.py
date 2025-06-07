from django.db import models
from django.core.validators import MinValueValidator, MaxValueValidator

class Book(models.Model):
    """
    Модель данных для представления книги.
    """
    GENRE_CHOICES = [
        ('fiction', 'Художественная литература'),
        ('non_fiction', 'Нехудожественная литература'),
        ('science', 'Научная литература'),
        ('fantasy', 'Фэнтези'),
        ('sci_fi', 'Научная фантастика'),
        ('detective', 'Детектив'),
        ('romance', 'Романтика'),
        ('horror', 'Ужасы'),
        ('other', 'Другое'),
    ]
    
    title = models.CharField(max_length=255, verbose_name='Название')
    author = models.CharField(max_length=255, verbose_name='Автор')
    publication_year = models.IntegerField(
        validators=[MinValueValidator(1000), MaxValueValidator(2100)],
        verbose_name='Год издания'
    )
    genre = models.CharField(
        max_length=20,
        choices=GENRE_CHOICES,
        default='other',
        verbose_name='Жанр'
    )
    pages = models.PositiveIntegerField(verbose_name='Количество страниц')
    rating = models.DecimalField(
        max_digits=3,
        decimal_places=1,
        validators=[MinValueValidator(0), MaxValueValidator(10)],
        verbose_name='Рейтинг'
    )
    is_bestseller = models.BooleanField(default=False, verbose_name='Бестселлер')
    created_at = models.DateTimeField(auto_now_add=True, verbose_name='Дата создания')
    updated_at = models.DateTimeField(auto_now=True, verbose_name='Дата обновления')
    
    def __str__(self):
        return f"{self.title} ({self.author})"
    
    class Meta:
        verbose_name = 'Книга'
        verbose_name_plural = 'Книги'
        ordering = ['-rating', 'title']

