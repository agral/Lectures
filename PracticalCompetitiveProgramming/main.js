function padZeroes(num, places=2) {
    return String(num).padStart(places, "0")
}

function CreateFooter(root, slideNum, totalSlides) {
    const footer = document.createElement("footer")
    const divLeft = document.createElement("div")
    divLeft.className = "left"
    if (slideNum > 1) {
        // Add a back button:
        const btnBack = document.createElement("a")
        btnBack.className = "btn btn-prev"
        btnBack.innerHTML = '<i class="fa-solid fa-arrow-left"></i>Prev Page'
        btnBack.href = "#slide" + padZeroes(slideNum-1)
        divLeft.appendChild(btnBack)
    }

    const divCenter = document.createElement("div")
    divCenter.className = "center"
    divCenter.innerHTML = padZeroes(slideNum) + " / " + padZeroes(totalSlides)

    const divRight = document.createElement("div")
    divRight.className = "right"
    if (slideNum < totalSlides) {
        // Add a forward button:
        const btnNext = document.createElement("a")
        btnNext.className = "btn btn-next"
        btnNext.innerHTML = 'Next Page<i class="fa-solid fa-arrow-right"></i>'
        btnNext.href = "#slide" + padZeroes(slideNum+1)
        divRight.appendChild(btnNext)
    }

    footer.appendChild(divLeft)
    footer.appendChild(divCenter)
    footer.appendChild(divRight)

    root.appendChild(footer)
}

function main() {
    let slides = document.getElementsByClassName("slide")

    for (let i = 0; i < slides.length; i++) {
        CreateFooter(slides[i], (i+1), slides.length)
    }
}

main()
