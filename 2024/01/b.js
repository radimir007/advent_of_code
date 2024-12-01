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

    first.forEach(item => {
        let count = 0
        second.filter(item2 => {
            if (item === item2) {
                count++
            }
        })

        result += item * count
    })

    console.log(result)
})