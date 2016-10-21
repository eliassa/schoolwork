'use strict';

const PORT=8080;

var fs = require('fs');
var https = require('https');
var express = require('express');
var CryptoJS = require('crypto-js');
var querystring = require('querystring');
var bodyParser = require('body-parser');

var hskey = fs.readFileSync(__dirname+'/sslcert/hacksparrow-key.pem');
var hscert = fs.readFileSync(__dirname+'/sslcert/hacksparrow-cert.pem')

var app = express();
var credentials = {
    key: hskey,
    cert: hscert
};

app.use(express.static(__dirname + "/../client"));

var https_server = https.createServer(credentials, app);

var salt="www.ntnu.no/tdat3020"+"sindre";
var key512Bits1000Iterations = CryptoJS.PBKDF2("gjerde", salt, { keySize: 512/32, iterations: 1000 });
/*
var salt = CryptoJS.lib.WordArray.random(128/8);
//var salt="www.ntnu.no/tdat3020"+this.username.value;
var key128Bits = CryptoJS.PBKDF2("gjerde", salt, { keySize: 128/32 });
var key256Bits = CryptoJS.PBKDF2("Secret Passphrase", salt, { keySize: 256/32 });
var key512Bits = CryptoJS.PBKDF2("Secret Passphrase", salt, { keySize: 512/32 });
//var key512Bits1000Iterations = CryptoJS.PBKDF2("Secret Passphrase", salt, { keySize: 512/32, iterations: 1000 });
*/
process.env.NODE_TLS_REJECT_UNAUTHORIZED = "0";


app.post("/authenticate",function(req,res){

  console.log("Prøver å logge inn");
  var bodyStr = '';
  req.on("data",function(chunk){
      bodyStr += chunk.toString();
      console.log("test2"+bodyStr);
      var cred = bodyStr.split(",");
      var uname = cred[0].split(":")[1];
      var pass = cred[1].split(":")[1];
      uname=uname.substring(1,uname.length-1);
      pass=pass.substring(1,pass.length-2);

      console.log(uname);
      console.log(pass);
      console.log(key512Bits1000Iterations.toString());
      if (uname ==='sindre'){
        console.log('riktig bruker');
        if (pass === key512Bits1000Iterations.toString()){
          console.log('riktig passord, logget inn');
        } else{
          console.log('galt passord');
        }
      }else{
        console.log("Feil bruker");
      }
      //var salt = "salt";
      //console.log(CryptoJS.PBKDF2(pass, salt, {keySize: 512/32, iterations: 10}));
  });
  req.on("end",function(){
      res.send('Aner ikke hva som skjer');
      console.log("test3");
  });

});

//Start the web server serving the We'bSocket client
//Open http://localhost:8080 in a web browser
var server=https_server.listen(PORT, () => {
  var host = server.address().address;
  var port = server.address().port;
  console.log('Example app listening at https://localhost:%s', port);
});
