const fs = require('fs')
const readline = require('readline')

const fileStream = fs.createReadStream('input.txt')

const rl = readline.createInterface({
  input: fileStream,
  crlfDelay: Infinity,
})

let input = []
let dimensions = {
    x: 0,
    y: 0
}

rl.on('line', (line) => {
    input.push(line)
})

const checkDirections = (xPos, yPos) => {

    let result = 0

    // Left
    if (xPos - 3 >= 0) {
        let temp = input[yPos].substr(xPos - 3, 4).split('').reverse().join('')
        if (temp === "XMAS") {
            result++
        }
    }

    // Right
    if (xPos + 3 <= dimensions.x) {
        let temp = input[yPos].substr(xPos, 4)
        if (temp === "XMAS") {
            result++
        }
    }

    // Down
    if (yPos + 3 <= dimensions.y) {
        let temp = input[yPos][xPos]
        for (let i = 1; i < 4; i++) {
            temp += input[yPos + i][xPos]
        }

        if (temp === "XMAS") {
            result++
        }
    }

    // Up
    if (yPos - 3 >= 0) {
        let temp = input[yPos][xPos]
        for (let i = 1; i < 4; i++) {
            temp += input[yPos - i][xPos]
        }

        if (temp === "XMAS") {
            result++
        }
    }

    // Diagonal left up
    if (xPos - 3 >= 0 && yPos - 3 >= 0) {
        let temp = input[yPos][xPos]
        for (let i = 1; i < 4; i++) {
            temp += input[yPos - i][xPos - i]
        }

        if (temp === "XMAS") {
            result++
        }
    } 

    // Diagonal left down
    if (xPos - 3 >= 0 && yPos + 3 <= dimensions.y) {
        let temp = input[yPos][xPos]
        for (let i = 1; i < 4; i++) {
            temp += input[yPos + i][xPos - i]
        }

        if (temp === "XMAS") {
            result++
        }
    } 

    // Diagonal right up
    if (xPos + 3 <= dimensions.x && yPos - 3 >= 0) {
        let temp = input[yPos][xPos]
        for (let i = 1; i < 4; i++) {
            temp += input[yPos - i][xPos + i]
        }

        if (temp === "XMAS") {
            result++
        }
    }

    // Diagonal right down
    if (xPos + 3 <= dimensions.x && yPos + 3 <= dimensions.y) {
        let temp = input[yPos][xPos]
        for (let i = 1; i < 4; i++) {
            temp += input[yPos + i][xPos + i]
        }

        if (temp === "XMAS") {
            result++
        }
    }

    return result
}

rl.on('close', () => {

    dimensions.x = input[0].length - 1
    dimensions.y = input.length - 1

    let result = 0

    for (let i = 0; i < input.length; i++) {
        for (let j = 0; j < input[i].length; j++) {
            if (input[i][j] == "X") {
                result += checkDirections(j, i)
            }
        }
    }

    console.log(result)
})