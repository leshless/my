// const express = require("express")
// const app = express()
// const port = process.env.port || "8000"

// app.use(express.static(__dirname + "/public"))

// app.get('/', (req, res) => {
//     res.sendfile(path.join(__dirname + "index.html"))
// })
  
// app.listen(port, () => {
//     console.log(`Server is running on http://localhost:${port}`)
// })

const sql = require("sqlite3")
const db = new sql.Database("userdata.db")

const sqlreq = (command, method = "all") => {
    return new Promise((resolve, reject) => {
        db[method](command, (error, result) => {
            if (error){
                console.error(error)
                reject(error)
            }else{
                resolve(result)
            }
        })
    })
}

db.serialize(async () => {
    await sqlreq(`CREATE TABLE IF NOT EXISTS "user" (
                    "id"	INTEGER NOT NULL UNIQUE,
                    "name"	TEXT,
                    PRIMARY KEY("id")
                );`)
    
    await sqlreq("INSERT INTO user (name) VALUES ('John')", "run")
    console.log(await sqlreq("SELECT * FROM user"))
})  