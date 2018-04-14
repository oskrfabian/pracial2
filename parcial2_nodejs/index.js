const TelegramBot = require('node-telegram-bot-api');
 const token = '586106828:AAHNCn1kochGFaU25mysxF-LQR86cDL8Dek';
var idChar = 548250795;
 var SerialPort = require('serialport');
 var port = new SerialPort('/dev/cu.usbmodem1411', {
   baudRate: 57600
 });

 const bot = new TelegramBot(token, {polling: true});

 bot.on('message', (msg) => {
   const chatId = msg.chat.id;
   console.log("El id es " + chatId)
   var respuesta = msg.text;
   if (respuesta == "encender") {
     console.log("encender alarma");
     bot.sendMessage(chatId, 'Encendiendo zumbador');
     miSerial.write("E");
   } else if (respuesta == "apagar") {
     console.log("apagar alarma");
     bot.sendMessage(chatId, 'Apagando zumbador');
     miSerial.write("A");
   }
 });
 miSerial.setEncoding('utf8');

miSerial.on('data', function(data) {
  console.log('Data:', data);
  if (data[0] == 'E') {
    console.log("Boton precionado");
    bot.sendMessage(idChar, "Precionador el boton");
  }
});
