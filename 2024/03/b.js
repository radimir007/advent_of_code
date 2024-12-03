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

    const matches = [...input.matchAll(/mul\(\d+,\d+\)|do\(\)|don't\(\)/g)]

    console.log(matches.length)

    const indices = matches.map(match => match.index)

    let manip = true

    indices.forEach((indice, index) => {
        let nums = ["", ""]

        let currentNum = 0

        if (matches[index][0] === "do()") {
            manip = true
        } else if (matches[index][0] === "don't()") {
            manip = false
        } else {
            for (let i = indice + 4; ; i++) {
                if (input[i] === ',') {
                    currentNum = 1
                } else if (input[i] === ')') {
                    break
                } else {
                    nums[currentNum] += input[i]
                }
            }

            if (manip) {
                console.log("nums:", nums[0], nums[1])
                result += parseInt(nums[0]) * parseInt(nums[1])
                manip = true
            }
            
        }
    })

    console.log(result)

})