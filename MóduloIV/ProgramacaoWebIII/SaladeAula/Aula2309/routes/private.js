import User from "../model/User.js";
import express from "express";

const router = express.Router();

router.get("/listarUsuarios", (req, res)=>{
    try{
        const users = await User.find().select("-password");
        if(!users){
            return res.status(404).json({message: "Não há registros."});
        }
        return res.status(200).json({message: "Lista carregada com sucesso."});
    } catch(erro){
        res.status(500).json({message: `Deu ruim :(\n${erro})`});
    }
})

export default router;