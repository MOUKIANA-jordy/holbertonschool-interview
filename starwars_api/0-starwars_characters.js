#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(apiUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const data = JSON.parse(body);
  const characters = data.characters;

  const fetchCharacter = (url) => {
    return new Promise((resolve, reject) => {
      request(url, (err, res, bodyChar) => {
        if (err) {
          reject(err);
        } else {
          resolve(JSON.parse(bodyChar).name);
        }
      });
    });
  };

  (async () => {
    for (const url of characters) {
      try {
        const name = await fetchCharacter(url);
        console.log(name);
      } catch (err) {
        console.error(err);
      }
    }
  })();
});
