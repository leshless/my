var passVis = false;

const check = document.querySelector("#check")

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

function apply() {

    password = document.querySelector("#password").value

    username = document.querySelector("#username").value

    let logCheck = /^[A-Za-z0-9._\-]{6,20}$/

    let passCheck = /^[A-Za-z0-9-_.:;!@()&#]{8,20}$/

    if (logCheck.test(username)){

        if (passCheck.test(password)){

            alert("Добро пожаловать")

        }else {

            alert("Пароль не подходит")

        }

    }else{

        alert("Логин не подходит")

    }

}