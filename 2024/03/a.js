const fs = require('fs')
const readline = require('readline')

const fileStream = fs.createReadStream('input.txt')

const rl = readline.createInterface({
  input: fileStream,
  crlfDelay: Infinity,
})

let input = []

rl.on('line', (line) => {
    input = line
})

rl.on('close', () => {

    let result = 0

    const matches = [...input.matchAll(/mul\(\d+,\d+\)/g)]

    console.log(matches.length)

    const indices = matches.map(match => match.index)

    indices.forEach(indice => {
        let nums = ["", ""]

        let currentNum = 0

        for (let i = indice + 4; ; i++) {
            if (input[i] === ',') {
                currentNum = 1
            } else if (input[i] === ')') {
                break
            } else {
                nums[currentNum] += input[i]
            }
        }

        console.log("nums:", nums[0], nums[1])
        result += parseInt(nums[0]) * parseInt(nums[1])
    })

    console.log(result)

})