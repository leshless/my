const addr = "localhost:8000"

const checkMark = document.querySelector("#check")
const usernameInput = document.querySelector("#username")
const passwordInput = document.querySelector("#password")

const logCheck = /^[A-Za-z0-9._\-]{6,20}$/
const passCheck = /^[A-Za-z0-9-_.:;!@()&#]{8,20}$/

var passVis = false;
check.onclick = () => {
    password = document.querySelector("#password")
    if (!passVis){
        password.setAttribute("type", "name")
        passVis = true;
    }else {
        password.setAttribute("type", "password")
        passVis = false;
    }

}

async function login() {
    const username = usernameInput.value 
    const password = passwordInput.value

    if (logCheck.test(username)){
        if (passCheck.test(password)){
            query = {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                }
            }
            const reply = await fetch(m)

        }else {
            alert("Пароль не подходит") 
        }
    }else{
        alert("Логин не подходит")
    }

}