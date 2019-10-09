[![](https://iarduino.ru/img/logo.svg)](https://iarduino.ru)[![](https://wiki.iarduino.ru/img/git-shop.svg?3)](https://iarduino.ru) [![](https://wiki.iarduino.ru/img/git-wiki.svg?2)](https://wiki.iarduino.ru) [![](https://wiki.iarduino.ru/img/git-lesson.svg?2)](https://lesson.iarduino.ru)[![](https://wiki.iarduino.ru/img/git-forum.svg?2)](http://forum.trema.ru)

# iarduino_AM2320

**This is a library for Arduino IDE. It allows to control [Temperature and Humidity sensor](https://iarduino.ru/shop/Sensory-Datchiki/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul.html), I2C module made by iArduino.ru**

**Данная библиотека для Arduino IDE позволяет управлять модулем I2C [Цифровой датчик температуры и влажности](https://iarduino.ru/shop/Sensory-Datchiki/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul.html) от [iArduino.ru](https://iarduino.ru)**

> Подробнее про установку библиотеки читайте в нашей [инструкции](https://wiki.iarduino.ru/page/Installing_libraries/).

> Подробнее про подключение к [Arduino UNO](https://iarduino.ru/shop/boards/arduino-uno-r3.html)/[Piranha UNO](https://iarduino.ru/shop/boards/piranha-uno-r3.html) читайте на нашей [wiki](https://wiki.iarduino.ru/page/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul/#h3_3)


| Модель | Ссылка на магазин |
|---|---|
| Title <img src="https://wiki.iarduino.ru/img/resources/703/703.svg" width="150px"></img>| https://iarduino.ru/shop/Sensory-Datchiki/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul.html |


## Назначение функций:

**Подробное описание работы с библиотекой и примеры смотрите на [нашем сайте](https://wiki.iarduino.ru/page/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul/#h3_6)**

**Подключение библиотеки**

#include <Wire.h> // Подключаем библиотеку для работы с шиной I2C.
#include <iarduino_AM2320.h> // Подключаем библиотеку для работы с датчиком.
iarduino_AM2320 ОБЪЕКТ; // Создаём объект.

**Инициализация работы** 

```C++
ОБЪЕКТ.begin(); // Инициализация работы с датчиком AM2320.
```

**Чтение показаний** 

```C++
ОБЪЕКТ.read(); // Чтение показаний датчика в переменные tem и hum.
```

**Чтение температуры**

```C++
Переменная tem // (тип float) содержит прочитанное значение температуры окружающей среды в °C
```

**Чтение влажности**

```C++
Переменная hum // (тип float) содержит прочитанное значение влажности в %
```

