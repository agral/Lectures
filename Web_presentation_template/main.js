let currSlide = 1

function padZeroes(num, places=2) {
    return String(num).padStart(places, "0")
}

function modifyFooter() {
    let slideId = "slide" + padZeroes(currSlide, 2)
    let currSection = document.getElementById(slideId)
    if (currSection == null) {
        console.log("Error: could not find '" + slideId + "' which is the current slide.")
        console.log("Aborting modifyFooter(), navigation will not work.")
        return
    }
    let currFooter = currSection.getElementsByTagName("footer")[0];
    if (currFooter == null) {
        return
    }
    console.log("Successfully got hold of the current slide's footer.")
}

function InsertSlideNumber(footer, num, count) {
    let divCenter = footer.getElementsByClassName("center")[0]
    if (divCenter == null) {
        console.log("Error: could not find div.center in '" + footer + "'.")
        console.log("Please fix the syntax of slides in index.html.")
        return
    }
    divCenter.innerHTML = padZeroes(num) + " / " + padZeroes(count)
}

function DirectInsertSlideNumber(root, num, count) {
    root.innerHTML = padZeroes(num) + " / " + padZeroes(count)
}

function CreateFooter(root, slideNum, count) {
    const footer = document.createElement("footer")
    const divLeft = document.createElement("div")
    divLeft.className = "left"
    const divCenter = document.createElement("div")
    divCenter.className = "center"
    const divRight = document.createElement("div")
    divRight.className = "right"

    DirectInsertSlideNumber(divCenter, slideNum, count)

    footer.appendChild(divLeft)
    footer.appendChild(divCenter)
    footer.appendChild(divRight)

    root.appendChild(footer)
}

function main() {
    let slides = document.getElementsByClassName("slide")

    CreateFooter(slides[1], 2, slides.length)

    /*
    for (let i = 0; i < slides.length; i++) {
        let currFooter = slides[i].getElementsByTagName("footer")[0]
        if (currFooter == null) {
            console.log("Error: could not find a footer in slide#'" + (i+1) + "'.")
            console.log("Please fix the syntax of slides in index.html.")
            console.log("Aborting, navigation will not work.")
            return
        }
        InsertSlideNumber(currFooter, i+1, slides.length)
    }
    */
}

main()
