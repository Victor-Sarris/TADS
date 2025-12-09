import express from "express";
import {newCollectionManager, listCollectionManagers, deleteCollectionManager, updateCollectionManager } from "./collectionManager.controller.js"
import {authenticate, authorizaAdmin} from "../../middleware/authenticate.js"

const collectionManagerRouter = express.Router();
collectionManagerRouter.get("/collectionManagers?collectionId=:id", authenticate, authorizaAdmin, listCollectionManagers)
collectionManagerRouter.post("/collectionManagers", authenticate,  authorizaAdmin, newCollectionManager)
collectionManagerRouter.post("/collectionManagers/update", authenticate, authorizaAdmin, updateCollectionManager)
collectionManagerRouter.post("/collectionManagers/delete", authenticate, authorizaAdmin, deleteCollectionManager)

export default collectionManagerRouter; 