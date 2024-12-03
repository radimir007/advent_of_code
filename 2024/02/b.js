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

const checkLine = (line, increase) => {
    for (let i = 0; i < line.length - 1; i++) {
        const diff = line[i + 1] - line[i]
        if ((diff > 0) !== increase || Math.abs(diff) < 1 || Math.abs(diff) > 3) {
            return false
        }
    }
    return true
}
rl.on('close', () => {

    let result = 0

    input.forEach(line => {

        if (line.length < 2) return

        const initialIncrease = line[1] - line[0] > 0

        if (checkLine(line, initialIncrease)) {
            result++
        } else {
            for (let i = 0; i < line.length; i++) {
                const temp = [...line]

                temp.splice(i, 1)

                const increase = temp[1] - temp[0] > 0
                
                if (checkLine(temp, increase)) {
                    result++
                    break
                }
            }
        }
    })
    
    console.log(result)
})