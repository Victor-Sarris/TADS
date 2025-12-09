const express = require("express")
const router = express.Router()

router.get("/", (req, res)=>{
    res.send("Esta resposta vem no controller")
})

router.get("/rota2", (req, res)=>{
    res.send("Rota 2")
})

module.exports = router