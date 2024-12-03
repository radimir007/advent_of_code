const fs = require('fs')
const readline = require('readline')

const fileStream = fs.createReadStream('input.txt')

const rl = readline.createInterface({
  input: fileStream,
  crlfDelay: Infinity,
})

let input = []

rl.on('line', (line) => {
    input.push(line.split(" ").map(Number))
})

let index = 0

rl.on('close', () => {

    let result = 0

    input.forEach(line => {
        if (line[1] - line[0] != 0) {
            let increase = line[1] - line[0] > 0

            for (let i = 0; i < line.length; i++) {

                if (i === line.length - 1) {
                    result++
                    break
                }

                if (increase === (line[i+1] - line[i] > 0)) {
                    if (Math.abs(line[i+1] - line[i]) >= 1 && Math.abs(line[i+1] - line[i]) <= 3) {
                        continue
                    } else {
                        break
                    }
                } else {
                    break
                }
            }
        }

        
    })
    
    console.log(result)
})