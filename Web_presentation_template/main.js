function padZeroes(num, places=2) {
    return String(num).padStart(places, "0")
}

function CreateFooter(root, slideNum, totalSlides) {
    const footer = document.createElement("footer")
    const divLeft = document.createElement("div")
    divLeft.className = "left"
    const divCenter = document.createElement("div")
    divCenter.className = "center"
    const divRight = document.createElement("div")
    divRight.className = "right"

    divCenter.innerHTML = padZeroes(slideNum) + " / " + padZeroes(totalSlides)

    footer.appendChild(divLeft)
    footer.appendChild(divCenter)
    footer.appendChild(divRight)

    root.appendChild(footer)
}

function main() {
    let slides = document.getElementsByClassName("slide")

    for (let i = 0; i < slides.length; i++) {
        let currFooter = slides[i].getElementsByTagName("footer")[0]
        if (currFooter == null) {
            CreateFooter(slides[i], (i+1), slides.length)
        }
    }
}

main()
