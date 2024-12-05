const fs = require('fs')
const readline = require('readline')

const fileStream = fs.createReadStream('input.txt')

const rl = readline.createInterface({
  input: fileStream,
  crlfDelay: Infinity,
})

let rules = []
let pages = []

let currentLine = "rules"

rl.on('line', (line) => {

    if (line == "") {
        currentLine = "pages"
        return
    }

    if (currentLine === "rules") {
        const splitted = line.split('|')
        rules.push({
            first: parseInt(splitted[0]),
            second: parseInt(splitted[1])
        })
    } else {
        pages.push(line.split(',').map(Number))
    }
    
})


rl.on('close', () => {

    let result = 0

    pages.forEach(page => {

        isCorrect = true

        for (let i = 0; i < page.length; i++) {
            const matches = rules.filter(rule => {
                return rule.first === page[i]
            })

            for (let j = 0; j < i; j++) {
                for (let match of matches) {
                    if (match.second === page[j]) {
                        isCorrect = false
                        break
                    }
                }

                if (!isCorrect) {
                    break
                }
            }

            if (!isCorrect) {
                break
            }
        }

        if (isCorrect) {
            const middle = Math.floor(page.length / 2)
            result += page[middle]
        }
    })

    console.log(result)

})