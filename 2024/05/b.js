const fs = require('fs')
const { after } = require('node:test')
const readline = require('readline')

const fileStream = fs.createReadStream('input.txt')

const start = Date.now();

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

        const oldArr = [...page]

        for (let i = 0; i < page.length; i++) {
            const matches = rules.filter(rule => {
                return rule.first === page[i]
            })

            for (let match of matches) {
                const prev = page.slice(0, i)
                const index = prev.indexOf(match.second)
                if (index !== -1) {
                    page.splice(i+1, 0, page[index])
                    page.splice(index, 1)

                    i--
                }
            }
        }

        let isCorrect = true

        for (let i = 0; i < page.length; i++) {
            if (page[i] !== oldArr[i]) {
                isCorrect = false
                break
            }
        }

        if (!isCorrect) {
            const middle = Math.floor(page.length / 2)

            result += parseInt(page[middle])
        }
    })

    const end = Date.now();

    console.log(`Execution time: ${end - start} ms`);

    console.log(result)

})