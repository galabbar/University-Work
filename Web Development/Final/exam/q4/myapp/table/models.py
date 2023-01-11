from django.db import models


class schedule(models.Model):

    num = models.CharField(max_length=255)
    instructor = models.CharField(max_length=255)
    title = models.CharField(max_length=255)


class instructor(models.Model):

    instructorNum = models.CharField(max_length=255)
    name = models.CharField(max_length=255)
    exp = models.CharField(max_length=255)
