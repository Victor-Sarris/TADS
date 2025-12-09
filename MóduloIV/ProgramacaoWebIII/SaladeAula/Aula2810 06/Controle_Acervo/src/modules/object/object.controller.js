import {createObject, 
    findAllObjects, 
    update,
    deleteObjectById} from "./object.service.js"

//CREATE
export const newObject = async (req, res) => {
    try{
        await createObject(req.body)
        res.status(201).json({message: "Objeto cadastrada."})
    }catch(erro){
        res.status(502).json({erro: `${erro}`})
    }
}
//READ 
export const listObjects = async (req, res) =>{
    try{
        const objects = await findAllObjects()
        if(!objects){
            return res.status(404).json({message: "Não há registros."})
        }
        res.status(200).json({message: "Lista carregada com sucesso. ", objects})
    }catch(erro){
        res.status(500).json({message:  `Erro interno:( \n${erro}`})
    }
}

export const updateObject = async (req, res) =>{
    try{
        const object = req.body
        await update(object)
        res.status(200).json({message: "Objeto atualizada com sucesso."})
    }catch(erro){
        res.status(400).json({message:  `Erro:( \n${erro}`})
    }
}

export const deleteObject = async (req, res) =>{
    try{
        const { id } = req.body; 
        if (!id) {
            return res.status(400).json({ message: "ID do objeto é obrigatório para deletar." });
        }
        const deletedRows = await deleteObjectById(id);
        if (deletedRows === 0) {
            return res.status(404).json({ message: `Objeto com ID ${id} não encontrada para exclusão.` });
        }
        return res.status(200).json({message: "Objeto deletada permanentemente com sucesso."});
    }catch(erro){
        return res.status(500).json({message: `Erro interno ao tentar deletar: \n${erro.message}`})
    }
}