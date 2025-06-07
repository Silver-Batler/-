from django.contrib import admin
from django.urls import path, include
from rest_framework.routers import DefaultRouter
from mainapp.views import BookViewSet

# Создаем роутер и регистрируем наши ViewSets
router = DefaultRouter()
router.register(r'books', BookViewSet)

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/', include(router.urls)),
]

