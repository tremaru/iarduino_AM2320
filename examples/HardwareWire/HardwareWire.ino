// ПРИМЕР ВЫВОДА ТЕМПЕРАТУРЫ И ВЛАЖНОСТИ:                                        //
                                                                                 //
// Цифровой датчик температуры и влажности I2C (Trema-модуль):                   // https://iarduino.ru/shop/Sensory-Datchiki/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                                    // https://wiki.iarduino.ru/page/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul/
                                                                                 //
#include <Wire.h>                                                                // Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_AM2320.
#include <iarduino_AM2320.h>                                                     // Подключаем библиотеку iarduino_AM2320.
iarduino_AM2320 sensor;                                                          // Объявляем объект sensor для работы с датчиком AM2320, используя функции и методы библиотеки iarduino_AM2320.
                                                                                 //
void setup(){                                                                    //
     sensor.begin(&Wire); // &Wire1, &Wire2 ...                                  // Инициируем работу с датчиком AM2320, указав ссылку на объект для работы с шиной I2C на которой находится датчик.
     Serial.begin(9600);                                                         // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бод.
}                                                                                // Объект основной аппаратной шины I2C (Wire) можно не указывать: sensor.begin();
                                                                                 //
void loop(){                                                                     //
     switch(sensor.read()){                                                      // Читаем показания датчика.
         case AM2320_OK:         Serial.print  ("Датчик AM2320: ");              //
                                 Serial.print  ((String) "t="+sensor.tem+"*C, ");// Выводим температуру в °С.
                                 Serial.print  ((String)"PH="+sensor.hum+"%");   // Выводим относительную влажность в %.
                                 Serial.println();                        break; //
         case AM2320_ERROR_LEN:  Serial.println("Превышен объем буфера"); break; // Объем передаваемых данных превышает буфер I2C.
         case AM2320_ERROR_ADDR: Serial.println("Датчик не обнаружен");   break; // Получен NACK при передаче адреса датчика.
         case AM2320_ERROR_DATA: Serial.println("Ошибка данных");         break; // Получен NACK при передаче данных датчику.
         case AM2320_ERROR_SEND: Serial.println("Ошибка передачи");       break; // Ошибка при передаче данных.
         case AM2320_ERROR_READ: Serial.println("Ошибка чтения");         break; // Получен пустой ответ датчика.
         case AM2320_ERROR_ANS:  Serial.println("Ответ некорректен");     break; // Ответ датчика не соответствует запросу.
         case AM2320_ERROR_LINE: Serial.println("Помехи на линии");       break; // Помехи в линии связи (не совпадает CRC).
     }                                                                           //
     delay(2000);                                                                //
}                                                                                //
