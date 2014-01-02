#include <string.h>
char unitID_in[10];
char command_in[10];
char data_in[100];
///инициализация портов моторшилда
int Right = 4;
int Left = 7;
int NApr = 5;
int Napl = 6;
int ledPin = 2; //инициализируем лампу на порт 2
int ledPin2 = 9; //И лампу на 9
void setup() {
Serial.begin(9600); //Настройки скорости в Бодах
}
//постоянно повторяем цикл_
void loop() {
int i=0;
char buffer[100];
//Считывание значений фоторезистора
// и терморезистора
pinMode(ledPin, OUTPUT);
int sensorValue = analogRead(A0);
int sensorValue1 = analogRead(A1);
// Пишем значения
Serial.println("Light:"); //|
Serial.println(sensorValue1);//|
Serial.println("Temp:");// |
Serial.println(sensorValue);//|
if (sensorValue1 < 16) { //Если значение сенсора света падают ниже положеного, включаем освещение
digitalWrite(ledPin, HIGH);
}
else {
digitalWrite(ledPin,LOW);
}
delay(3000); // задержечка 5 сек
//если есть данные - читаем
if(Serial.available()){
delay(100);
//загоняем прочитанное в буфер
while( Serial.available() && i< 99) {
buffer[i++] = Serial.read();
}
//закрываем массив
buffer[i++]='\0';
}
//если буфер наполнен
if(i>0){
//разбераем его на части отделенные запятой
sscanf(buffer, "%[^','],%[^','],%s", &unitID_in, &command_in, &data_in);
}
//Исполнительная часть
//какому устройству пришли данные
//пример выполнения команды устройством 1
if ((String)unitID_in == "1")
{
if ((String)command_in == "3"){
analogWrite(7, 222);}{
if ((String)command_in == "3"){
analogWrite(6, 222);}{
if ((String)command_in == "3"){
analogWrite(5, 222);}{
if ((String)command_in == "3"){
analogWrite(4, 222);}

{
if ((String)command_in == "0"){
digitalWrite(ledPin2, 0);}
if ((String)command_in == "1"){
analogWrite(ledPin2, 100);
Serial.print("1,arduino recive: unit ");
Serial.print(unitID_in);
Serial.print(" command ");
Serial.print(command_in);
Serial.print("\n");
unitID_in [0] = '\0';
command_in [0] = '\0';}}}}}}}
