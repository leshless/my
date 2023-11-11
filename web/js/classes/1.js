class vehicle{
    constructor(type, speed, height, length, width){
        this.type = type
        this.speed = speed
        this.height = height
        this.length = length
        this.width = width
    }
}

class car extends vehicle{
    constructor(type, speed, height, length, width, model){
        super(type, speed, height, length, width)
        this.model = model
    }

    Beep(){
        console.log("BEEEEEEEEEEEP!")
    }
}


const mycar = new car("наземный", 100, 50, 100, 40, "пикап")
console.log(mycar)
mycar.Beep()
