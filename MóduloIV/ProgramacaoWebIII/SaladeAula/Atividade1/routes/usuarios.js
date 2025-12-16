const express = require('express');
const router = express.Router();

// --- EXERCÍCIO 10: Rotas do Controller ---

// Rota /usuarios/ -> Lista de usuários
router.get('/', (req, res) => {
    res.json([
        { id: 1, nome: "João" },
        { id: 2, nome: "Maria" },
        { id: 3, nome: "Pedro" }
    ]);
});

// Rota /usuarios/:id -> Detalhes do usuário 
router.get('/:id', (req, res) => {
    const id = req.params.id;
    res.send(`Detalhes do usuário com ID: ${id}`);
});

module.exports = router;