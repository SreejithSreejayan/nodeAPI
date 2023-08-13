const express = require('express');
const fs = require('fs');
const path = require('path');
const app = express();
const PORT = process.env.PORT || 8081;

app.get('/', async (req, res) => {
  res.json("Try endpoint'/list' to view the labs");
});

app.get('/list', (req, res) => {
    res.json({ "1":"network" ,"2":"os"});
});

app.get('/:dir', (req, res) => {
  const { dir } = req.params;
  const directoryPath = path.join(__dirname,dir); 

  fs.readdir(directoryPath, (err, files) => {
    if (err) {
      return res.status(500).json({ error: 'Error reading the directory.' });
    }
    res.json(files);
  });
});

app.get('/:dir/:prgm', (req, res) => {
  const { dir,prgm } = req.params;
  const directoryPath = path.join(__dirname, dir); 
  const filePath = path.join(directoryPath, prgm); 

  fs.readFile(filePath, 'utf8', (err, data) => {
    if (err) {
      return res.status(500).json({ error: 'Error reading the file.' });
    }
    res.writeHead(200, { 'Content-Type': 'text/c' });
    res.end(data);
  });
});

app.listen(PORT, () => {
  console.log(`server started on port ${PORT}`);
});