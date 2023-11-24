const express = require("express")
const app = express()
const port = process.env.port || "8000"

app.use(express.static(__dirname + "/public"))

app.get('/', (req, res) => {
    res.sendfile(path.join(__dirname + "index.html"))
})
  
app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`)
})

