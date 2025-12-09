import {createCollectionManager, 
    findAllCollectionManagers, 
    update,
    deleteCollectionManagerById} from "./collectionManager.service.js"

//CREATE
export const newCollectionManager = async (req, res) => {
    try{
        await createCollectionManager(req.body)
        res.status(201).json({message: "Coleção cadastrada."})
    }catch(erro){
        res.status(502).json({erro: `${erro}`})
    }
}
//READ 
export const listCollectionManagers = async (req, res) =>{
    try{
        const collectionManager = await findAllCollectionManagers()
        if(!collectionManager){
            return res.status(404).json({message: "Não há registros."})
        }
        res.status(200).json({message: "Lista carregada com sucesso. ", collectionManager})
    }catch(erro){
        res.status(500).json({message:  `Erro interno:( \n${erro}`})
    }
}

export const updateCollectionManager = async (req, res) =>{
    try{
        const collectionManager = req.body
        await update(collectionManager)
        res.status(200).json({message: "Coleção atualizada com sucesso."})
    }catch(erro){
        res.status(400).json({message:  `Erro:( \n${erro}`})
    }
}

export const deleteCollectionManager = async (req, res) =>{
    try{
        const { id } = req.body; 
        if (!id) {
            return res.status(400).json({ message: "ID da coleção é obrigatório para deletar." });
        }
        const deletedRows = await deleteCollectionManagerById(id);
        if (deletedRows === 0) {
            return res.status(404).json({ message: `Coleção com ID ${id} não encontrada para exclusão.` });
        }
        return res.status(200).json({message: "Coleção deletada permanentemente com sucesso."});
    }catch(erro){
        return res.status(500).json({message: `Erro interno ao tentar deletar: \n${erro.message}`})
    }
}