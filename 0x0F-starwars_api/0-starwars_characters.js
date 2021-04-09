#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

const firstName = function () {
  request(url, function (error, response, body) {
    if (error) throw error;
    secondName(JSON.parse(body).characters, 0);
  });
};

const secondName = function (characters, i) {
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
