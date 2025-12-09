import express from "express";
import {listUsers, deleteUser, updateUser, UpdateUserIsAdmin } from "../controllers/userController.js"
import { authorizaAdmin } from "../middleware/authenticate.js";

const router = express.Router();
// USUARIOS COMUNS
router.get("/listarUsuarios", listUsers)
router.post("/deletarUsuario", deleteUser)

// USUARIO ADMINISTRADORES
router.post("/atualizarUsuario",authorizaAdmin, updateUser)
// CRIAR ROTA PARA ELEVAR PRIVILÉGIOS DE USUÁRIO
router.post("/addUsarioAdmin", UpdateUserIsAdmin)

export default router;