#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

let firstName = function () {
  request(url, function (error, response, body) {
    if (error) throw error;
    let i = 0;
    secondName(JSON.parse(body).characters, i);
  });
};

let secondName = function (characters, i) {
  if (characters.length === i) {
    return;
  }
  request(characters[i], function (error, response, body) {
    if (error) throw error;
    console.log(JSON.parse(body).name);
    secondName(characters, ++i);
  });
};

firstName();
