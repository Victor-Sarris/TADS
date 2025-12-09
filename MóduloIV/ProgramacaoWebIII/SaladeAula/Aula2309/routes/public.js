import express from "express";
import mongoose from "mongoose";
import conectDB from "../db.js";
import bcrypt from "bcrypt";
import User from "../model/User.js";

const router = express.Router();
//CRUD
//C = Create 
router.post("/cadastro", async (req, res) => {
    try {
        const usuario = req.body;
        const constFactor = 10; // 2^10 = 1024 interações
        usuario.password = bcrypt.hashSync(usuario.password, constFactor);

        await User.create(usuario); // C do CRUD
        res.status(200).json({message: "Usuário Cadastrado."})
    } catch (erro) {
        res.status(502) // 500 é um erro do servidor 
        console.log(`erro ao conectar no MongoDB: ${erro}`);
    }
})
//R = Retreave/Recuperar
//login
//U = Update
//D = Delete
router.post("/login", async (req, res) => {
    const usuario = req.body;
    console.log()
    try{
       const user = await User.findOne({email: usuario.email});
       if(!user){
        return res.status(401).json({message: "Usuário não cadastrado!"})
       }
       if (!bcrypt.compare(usuario.password, user.password)){
        return res.status(401).json({message: "Senha inválida!"})
       }
       const token = jwt.sign(
                { id: user.id, isAdmin: user.isAdmin },
                process.env.SECRET_JWT,
                {expiresIn: "2h"} // s/ m/ h/ d/ w/ M/ y
        )
    res.status(200).json({message: "Login realizado.", token});    
    } catch(erro){
        res.status(500).json({message: `Deu ruim :( \n${erro})`});
    }
})


export default router; 