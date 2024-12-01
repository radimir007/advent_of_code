const fs = require('fs')
const readline = require('readline')

const fileStream = fs.createReadStream('input.txt')

const rl = readline.createInterface({
  input: fileStream,
  crlfDelay: Infinity,
})

let first = []
let second = []

rl.on('line', (line) => {
    let temp = line.split("   ")
    first.push(parseInt(temp[0]))
    second.push(parseInt(temp[1]))
})

rl.on('close', () => {

    let result = 0

    first.sort()

    second.sort()

    first.forEach((item, index) => {
        result += Math.abs(item - second[index])
    })

    console.log(result)
})