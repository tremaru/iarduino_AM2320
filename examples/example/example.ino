//  Раскомментируйте для программной реализации шины I2C:                   //
//  #define pin_SW_SDA 3                                                    // Назначение любого вывода Arduino для работы в качестве линии SDA программной шины I2C.
//  #define pin_SW_SCL 9                                                    // Назначение любого вывода Arduino для работы в качестве линии SCL программной шины I2C.
//  Раскомментируйте для совместимости с большинством плат:                 //
//  #include <Wire.h>                                                       // Библиотека iarduino_AM2320 будет использовать методы и функции библиотеки Wire.
//  Ссылки для ознакомления:                                                //
//  Подробная информация о подключении модуля к шине I2C:                   // http://wiki.iarduino.ru/page/i2c_connection/
//  Подробная информация о функциях и методах библиотеки:                   // http://wiki.iarduino.ru/page/cifrovoy-datchik-temperatury-i-vlazhnosti-i2c-trema-modul/
                                                                            //
#include <iarduino_AM2320.h>                                                // Подключаем библиотеку iarduino_AM2320.
iarduino_AM2320 sensor;                                                     // Объявляем объект sensor для работы с датчиком AM2320, используя функции и методы библиотеки iarduino_AM2320.
                                                                            //
void setup(){                                                               //
  sensor.begin();                                                           // Инициируем работу с датчиком AM2320.
  Serial.begin(9600);                                                       // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бод.
}                                                                           //
                                                                            //
void loop(){                                                                //
  switch(sensor.read()){                                                    // Читаем показания датчика.
    case AM2320_OK:         Serial.println((String) "CEHCOP AM2320:  T=" + sensor.tem + "*C, PH=" + sensor.hum + "%");  break;
    case AM2320_ERROR_LEN:  Serial.println("OTIIPABKA HEBO3M.");     break; // Объем передаваемых данных превышает буфер I2C
    case AM2320_ERROR_ADDR: Serial.println("HET CEHCOPA");           break; // Получен NACK при передаче адреса датчика
    case AM2320_ERROR_DATA: Serial.println("OTIIPABKA HEBO3M.");     break; // Получен NACK при передаче данных датчику
    case AM2320_ERROR_SEND: Serial.println("OTIIPABKA HEBO3M.");     break; // Ошибка при передаче данных
    case AM2320_ERROR_READ: Serial.println("HET OTBETA OT CEHCOPA"); break; // Получен пустой ответ датчика
    case AM2320_ERROR_ANS:  Serial.println("OTBET HEKOPPEKTEH");     break; // Ответ датчика не соответствует запросу
    case AM2320_ERROR_LINE: Serial.println("HEPABEHCTBO CRC");       break; // Помехи в линии связи (не совпадает CRC)
  }                                                                         //
  delay(2000);                                                              //
}                                                                           //
