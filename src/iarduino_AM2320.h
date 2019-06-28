//	Библиотека для работы с датчиком температуры и влажности AM2320: http://iarduino.ru/shop/Sensory-Datchiki/cifrovoy-datchik-temperatury-i-vlazhnosti-am2320.html
//  Версия: 1.1.1
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/file/265.html
//  Подробное описание функции бибилиотеки доступно по ссылке: http://wiki.iarduino.ru/page/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef iarduino_AM2320_h													//
#define iarduino_AM2320_h													//
																			//
#if defined(ARDUINO) && (ARDUINO >= 100)									//
#include <Arduino.h>														//
#else																		//
#include <WProgram.h>														//
#endif																		//
																			//
#include <iarduino_AM2320_I2C.h>											//	Подключаем файл iarduino_RTC_I2C.h - для работы с шиной I2C        (используя функции производного класса iarduino_I2C)
																			//
#define	AM2320_OK			0												//	Успешное чтение данных
#define	AM2320_ERROR_LEN	1												//	Объем передаваемых данных превышает буфер I2C
#define	AM2320_ERROR_ADDR	2												//	Получен NACK при передаче адреса
#define	AM2320_ERROR_DATA	3												//	Получен NACK при передаче данных
#define	AM2320_ERROR_SEND	4												//	Ошибка при передаче данных
#define	AM2320_ERROR_READ	5												//	Получен пустой ответ датчика
#define	AM2320_ERROR_ANS	6												//	Ответ датчика не соответствует запросу
#define	AM2320_ERROR_LINE	7												//	Помехи в линии связи (не совпадает CRC)
																			//
class iarduino_AM2320{														//
	public:																	//
	/**	Конструктор класса **/												//
		iarduino_AM2320(){	objI2C = new iarduino_I2C; }					//	Конструктор основного класса
	/**	функции доступные пользователю **/									//
		void				begin();										//	Инициализация датчика
		uint8_t				read();											//	Возвращает № ошибки, см. константы выше
	/**	переменные доступные пользователю **/								//
		float 				hum;											//	Значение влажности   в %
		float				tem;											//	Значение температуры в °C
	private:																//
	/**	внутренние функции **/												//
		uint16_t			createCRC16(uint8_t*,uint8_t);					//	Создание CRC16 (массив данных, длина массива)
	/**	внутренние переменные **/											//
		iarduino_I2C_BASE*	objI2C;											//	Объявляем указатель на объект полиморфного класса iarduino_I2C_BASE, но в конструкторе данного класса этому указателю будет присвоена ссылка на производный класс iarduino_I2C
		int8_t				VAR_address = 0x5C;								//	Адрес датчика на шине I2C
		uint32_t			TIM_request = 0xffffffff;						//	Время последнего запроса к датчику
};																			//
																			//
#endif																		//