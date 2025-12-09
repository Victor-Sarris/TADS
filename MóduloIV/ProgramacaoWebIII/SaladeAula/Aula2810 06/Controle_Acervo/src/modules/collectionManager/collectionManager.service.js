import CollectionManager from "./collectionManager.model.js";
export const createCollectionManager = async (collectionManager)=>{
    return CollectionManager.create(collectionManager);
}
export const findAllCollectionManagers = async () =>{
    return CollectionManager.findAll()
}
export const update = async (collectionManager) =>{
    return CollectionManager.update(collectionManager, {where: {id: collectionManager.id}})
}
export const deleteCollectionManagerById = async (collectionManagerId) =>{
    return CollectionManager.destroy({where: { id: collectionManagerId }})
}