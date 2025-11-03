let currSlide = 1

function padZeroes(num, places) {
    return String(num).padStart(places, "0")
}

function modifyFooter() {
    const slideId = "slide" + padZeroes(currSlide, 2)
    let currSection = document.getElementById(slideId)
    if (currSection == null) {
        console.log("Error: could not find '" + slideId + "' which is the current slide.")
        console.log("Aborting modifyFooter(), navigation will not work.")
        return
    }
    let currFooter = currSection.getElementsByTagName("footer")[0];
    if (currFooter == null) {
        console.log("Error: could not find a footer in'" + slideId + "'.")
        console.log("Please fix the syntax of slides in index.html.")
        console.log("Aborting modifyFooter(), navigation will not work.")
        return
    }
    console.log("Successfully got hold of the current slide's footer.")
}
console.log("test")
modifyFooter()
