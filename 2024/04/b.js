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

    let temp1 = "", temp2 = ""

    if (yPos - 1 >= 0 && xPos - 1 >= 0 && yPos + 1 <= dimensions.y && xPos + 1 <= dimensions.x) {
        temp1 = input[yPos - 1][xPos - 1] + "A" + input[yPos + 1][xPos + 1]
        temp2 = input[yPos - 1][xPos + 1] + "A" + input[yPos + 1][xPos - 1]
    } else {
        return false
    }

    if (temp1 === "MAS" || temp1 === "SAM") {
        if (temp2 === "MAS" || temp2 === "SAM") {
            return true
        }
    }

    return false
}

rl.on('close', () => {

    dimensions.x = input[0].length - 1
    dimensions.y = input.length - 1

    let result = 0

    for (let i = 0; i < input.length; i++) {
        for (let j = 0; j < input[i].length; j++) {
            if (input[i][j] == "A") {
                if(checkDirections(j, i)) {
                    result++
                }
            }
        }
    }

    console.log(result)
})