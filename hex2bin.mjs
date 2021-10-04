import { readFile } from "fs";

const b = (s) => parseInt(s, 16).toString(2).padStart(4, "0");

readFile("rom-words.txt", (err, data) => {
  if (err) return console.error(err);
  const res = data.toString().replace(/\w/g, b);
  console.log(res);
});
